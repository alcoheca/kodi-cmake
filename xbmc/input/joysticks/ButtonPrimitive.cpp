/*
 *      Copyright (C) 2014 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "ButtonPrimitive.h"

CButtonPrimitive::CButtonPrimitive(void)
  : m_type(),
    m_index(0),
    m_hatDirection(),
    m_semiAxisDirection()
{
}

CButtonPrimitive::CButtonPrimitive(unsigned int buttonIndex)
  : m_type(ButtonPrimitiveTypeButton),
    m_index(buttonIndex),
    m_hatDirection(),
    m_semiAxisDirection()
{
}

CButtonPrimitive::CButtonPrimitive(unsigned int hatIndex, HatDirection direction)
  : m_type(ButtonPrimitiveTypeHatDirection),
    m_index(hatIndex),
    m_hatDirection(direction),
    m_semiAxisDirection()
{
}

CButtonPrimitive::CButtonPrimitive(unsigned int axisIndex, SemiAxisDirection direction)
  : m_type(ButtonPrimitiveTypeSemiAxis),
    m_index(axisIndex),
    m_hatDirection(),
    m_semiAxisDirection(direction)
{
}

bool CButtonPrimitive::operator==(const CButtonPrimitive& rhs) const
{
  if (m_type == rhs.m_type)
  {
    switch (m_type)
    {
    case ButtonPrimitiveTypeButton:
      return m_index == rhs.m_index;
    case ButtonPrimitiveTypeHatDirection:
      return m_index == rhs.m_index && m_hatDirection == rhs.m_hatDirection;
    case ButtonPrimitiveTypeSemiAxis:
      return m_index == rhs.m_index && m_semiAxisDirection == rhs.m_semiAxisDirection;
    default:
      return true;
    }
  }
  return false;
}

bool CButtonPrimitive::operator<(const CButtonPrimitive& rhs) const
{
  if (m_type < rhs.m_type) return true;
  if (m_type > rhs.m_type) return false;

  if (m_type)
  {
    if (m_index < rhs.m_index) return true;
    if (m_index > rhs.m_index) return false;
  }

  if (m_type == ButtonPrimitiveTypeHatDirection)
  {
    if (m_hatDirection < rhs.m_hatDirection) return true;
    if (m_hatDirection > rhs.m_hatDirection) return false;
  }

  if (m_type == ButtonPrimitiveTypeSemiAxis)
  {
    if (m_semiAxisDirection < rhs.m_semiAxisDirection) return true;
    if (m_semiAxisDirection > rhs.m_semiAxisDirection) return false;
  }

  return false;
}

bool CButtonPrimitive::IsValid(void) const
{
  return m_type == ButtonPrimitiveTypeButton ||
        (m_type == ButtonPrimitiveTypeHatDirection && (m_hatDirection == HatDirectionLeft  ||
                                                       m_hatDirection == HatDirectionRight ||
                                                       m_hatDirection == HatDirectionUp    ||
                                                       m_hatDirection == HatDirectionDown))  ||
        (m_type == ButtonPrimitiveTypeSemiAxis && (m_semiAxisDirection == SemiAxisDirectionPositive ||
                                                   m_semiAxisDirection == SemiAxisDirectionNegative));
                                                   
}
