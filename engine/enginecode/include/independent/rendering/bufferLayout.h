/** \file bufferLayout.h */
#pragma once

#include "shaderDataType.h"
#include <vector>
namespace Engine
{
	/** 
	\class Buffer Element
	A class which holds data about a single element in a buffer layout
	*/
	class BufferElement
	{
	public:
		ShaderDataType m_dataType;
		uint32_t m_size;
		uint32_t m_offset;
		bool m_normalised;

		BufferElement() {} //!< Default Constructor
		BufferElement(ShaderDataType dataType, bool normalised = false) :
			m_dataType(dataType),
			m_size(SDT::size(dataType)),
			m_offset(0),
			m_normalised(normalised)
		{} //!< Constructor with paramaters
	};
	/**
\class BufferLayout
* Abstraction of the notion of a buffer layout
*/
	class BufferLayout
	{
	public:
		BufferLayout() {};
		BufferLayout(const std::initializer_list<BufferElement>& element) : m_elements(element) { calcStrideAndOffset(); };
		inline uint32_t getStride() { return m_stride; }
		void addElement(BufferElement element);
		std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_elements.end(); }
		std::vector<BufferElement>::const_iterator begin()  const { return m_elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_elements.end(); }
	private:
		std::vector<BufferElement> m_elements; //!< Buffer elements
		uint32_t m_stride;
		void calcStrideAndOffset(); //!< Calculate stride and offsets based on elements
	};

	void BufferLayout::addElement(BufferElement element)
	{
		m_elements.push_back(element);
		calcStrideAndOffset();
	}

	void BufferLayout::calcStrideAndOffset()
	{
		uint32_t l_offset = 0;

		for (auto& element : m_elements)
		{
			element.m_offset = l_offset;
			l_offset += element.m_size;
		}

		m_stride = l_offset;
	}
}