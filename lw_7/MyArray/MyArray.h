#pragma once
#include <algorithm>
#include <boost/iterator/iterator_facade.hpp>

template <typename T>
class CMyArray
{
public:
	CMyArray() = default;

	//конструктор копирования
	CMyArray(const CMyArray &arr)
	{
		const auto size = arr.GetSize();
		if (size != 0)
		{
			m_begin = RawAlloc(size);
			try
			{
				CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
				m_endOfCapacity = m_end;
			}
			catch (...)
			{
				DeleteItems(m_begin, m_end);
				throw;
			}
		}
	}

	//конструктор перемещения
	CMyArray(CMyArray &&arr)
		:m_begin(arr.m_begin)
		, m_end(arr.m_end)
		, m_endOfCapacity(arr.m_endOfCapacity)
	{
		arr.m_begin = nullptr;
		arr.m_end = nullptr;
		arr.m_endOfCapacity = nullptr;
	}

	void Append(const T &value)
	{
		if (m_end == m_endOfCapacity) // no free space
		{
			size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T *newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				// Конструируем копию value по адресу newItemLocation
				new (newEnd)T(value);
				++newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);

			// Переключаемся на использование нового хранилища элементов
			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;
		}
		else // has free space
		{
			new (m_end) T(value);
			++m_end;
		}
	}

	size_t GetCapacity() const noexcept
	{
		return m_endOfCapacity - m_begin;
	}

	size_t GetSize() const noexcept
	{
		return m_end - m_begin;
	}

	T &operator[](size_t position)
	{
		if (position >= GetSize())
		{
			throw std::out_of_range("Element is out of range");
		}

		return m_begin[position];
	}

	const T &operator[](size_t position) const
	{
		if (position >= GetSize())
		{
			throw std::out_of_range("Element is out of range");
		}

		return m_begin[position];
	}

	void Resize(size_t newSize)
	{
		size_t currentSize = GetSize();

		if (newSize < currentSize)
		{
			DestroyItems(m_begin + newSize, m_end);
			m_end = m_end - (currentSize - newSize);
		}
		else if (newSize > currentSize && newSize <= GetCapacity())
		{
			T *oldEnd = m_end;
			try
			{
				for (size_t i = 0; i < newSize - currentSize; ++i)
				{
					Append(T());
				}
			}
			catch (...)
			{
				DeleteItems(oldEnd + 1, m_end);
				m_end = oldEnd;
				throw;
			}
		}
		else if (newSize > GetCapacity())
		{
			auto newBegin = RawAlloc(newSize);
			T *newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}

			DeleteItems(m_begin, m_end);

			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newSize;

			try
			{
				for (size_t i = GetSize(); i < GetCapacity(); ++i)
				{
					Append(T());
				}
			}
			catch (...)
			{
				DeleteItems(newEnd, m_end);
				m_end = newEnd;
				throw;
			}

		}
	}

	void Clear() noexcept
	{
		DestroyItems(m_begin, m_end);
		m_end = m_begin;
	}

	//Перемещающий оператор присваивания
	CMyArray &operator = (CMyArray && rhs) noexcept
	{
		if (&rhs != this)
		{
			Clear();
			m_begin = rhs.m_begin;
			m_end = rhs.m_end;
			m_endOfCapacity = rhs.m_endOfCapacity;

			rhs.m_begin = nullptr;
			rhs.m_end = nullptr;
			rhs.m_endOfCapacity = nullptr;
		}
		return *this;
	}

	//оператор присваивания
	CMyArray &operator = (CMyArray const &rhs) noexcept
	{
		if (this != std::addressof(rhs))
		{
			CMyArray newArr(rhs);

			std::swap(m_begin, newArr.m_begin);
			std::swap(m_end, newArr.m_end);
			std::swap(m_endOfCapacity, newArr.m_endOfCapacity);
		}
		return *this;
	}

	template<typename T>
	class CMyIterator : public boost::iterator_facade<CMyIterator<T>, T, std::random_access_iterator_tag>
	{
		template <typename> friend class CMyArray;
	public:

		T &CMyIterator<T>::operator *() const noexcept
		{
			return *m_pointer;
		};

		void increment()
		{
			++m_pointer;
		}

		void decrement()
		{
			--m_pointer;
		}

	private:
		CMyIterator(T *p)
			: m_pointer(p)
		{
		}

	private:
		T *m_pointer = nullptr;
	};

	CMyIterator<const T> begin() const noexcept
	{
		return CMyIterator<const T>(m_begin);
	}

	CMyIterator<const T> end() const noexcept
	{
		return CMyIterator<const T>(m_end);
	}

	std::reverse_iterator<CMyIterator<const T>> rbegin() const noexcept
	{
		return std::reverse_iterator<CMyIterator<const T>>(m_end);
	}

	std::reverse_iterator<CMyIterator<const T>> rend() const noexcept
	{
		return std::reverse_iterator<CMyIterator<const T>>(m_begin);
	}

	CMyIterator<const T> cbegin() const noexcept
	{	
		return (begin());
	}

	CMyIterator<const T> cend() const noexcept
	{
		return (end());
	}

	CMyIterator<const T> crbegin() const noexcept
	{
		return (rbegin());
	}

	CMyIterator<const T> crend() const noexcept
	{
		return (rend());
	}

	CMyIterator<T> begin() noexcept
	{
		return CMyIterator<T>(m_begin);
	}

	CMyIterator<T> end() noexcept
	{
		return CMyIterator<T>(m_end);
	}

	std::reverse_iterator<CMyIterator<T>> rbegin() noexcept
	{
		return std::reverse_iterator<CMyIterator<T>>(m_end);
	}

	std::reverse_iterator<CMyIterator<T>> rend() noexcept
	{
		return std::reverse_iterator<CMyIterator<T>>(m_begin);
	}

	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}

private:

	static T *RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T *p = static_cast<T*>(malloc(memSize));
		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void CopyItems(const T *srcBegin, T *srcEnd, T * const dstBegin, T * & dstEnd)
	{
		for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
		{
			new (dstEnd)T(*srcBegin);
		}
	}

	static void DeleteItems(T *begin, T *end)
	{
		// Разрушаем старые элементы
		DestroyItems(begin, end);
		// Освобождаем область памяти для их хранения
		RawDealloc(begin);
	}

	static void DestroyItems(T *from, T *to) noexcept
	{
		// dst - адрес объект, при конструирование которого было выброшено исключение
		// to - первый сконструированный объект
		while (to != from)
		{
			--to;
			// явно вызываем деструктор для шаблонного типа T
			to->~T();
		}
	}

	static void RawDealloc(T *p)
	{
		free(p);
	}

private:
	T * m_begin = nullptr;
	T *m_end = nullptr;
	T *m_endOfCapacity = nullptr;
};
