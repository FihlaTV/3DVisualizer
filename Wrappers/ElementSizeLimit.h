/***********************************************************************
ElementSizeLimit - Functor class to terminate creation of a
visualization element once it reaches a maximum size.
Copyright (c) 2009 Oliver Kreylos

This file is part of the 3D Data Visualizer (Visualizer).

The 3D Data Visualizer is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 2 of the License, or (at
your option) any later version.

The 3D Data Visualizer is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License along
with the 3D Data Visualizer; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
***********************************************************************/

#ifndef VISUALIZATION_WRAPPERS_ELEMENTSIZELIMIT_INCLUDED
#define VISUALIZATION_WRAPPERS_ELEMENTSIZELIMIT_INCLUDED

namespace Visualization {

namespace Wrappers {

template <class ElementParam>
class ElementSizeLimit
	{
	/* Embedded classes: */
	public:
	typedef ElementParam Element;
	
	/* Elements: */
	private:
	const Element& element; // The monitored visualization element
	size_t maxElementSize; // Maximum number of vertices/triangles/etc. to create
	
	/* Constructors and destructors: */
	public:
	ElementSizeLimit(const Element& sElement,size_t sMaxElementSize)
		:element(sElement),maxElementSize(sMaxElementSize)
		{
		}
	
	/* Methods: */
	bool operator()(void) const
		{
		return element.getElementSize()<maxElementSize;
		}
	};

}

}

#endif
