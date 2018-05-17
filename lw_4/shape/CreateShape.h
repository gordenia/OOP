#pragma once
#include "stdafx.h"
#include "Shape.h"

class CCreateShape
{
public:
	CCreateShape(std::istream &input);
	std::shared_ptr<CShape> ExecuteCommand() const;

private:
	std::shared_ptr<CShape> CreateLine(std::istream &args) const;
	std::shared_ptr<CShape> CreateTriangle(std::istream &args) const;
	std::shared_ptr<CShape> CreateRectangle(std::istream &args) const;
	std::shared_ptr<CShape> CreateCircle(std::istream &args) const;
private:
	typedef std::map<std::string, std::function<std::shared_ptr<CShape>(std::istream & args)>> ActionMap;
	std::istream &m_input;
	const ActionMap m_actionMap;
};

