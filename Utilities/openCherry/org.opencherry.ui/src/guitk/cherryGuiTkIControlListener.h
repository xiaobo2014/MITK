/*=========================================================================

 Program:   openCherry Platform
 Language:  C++
 Date:      $Date$
 Version:   $Revision$

 Copyright (c) German Cancer Research Center, Division of Medical and
 Biological Informatics. All rights reserved.
 See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notices for more information.

 =========================================================================*/

#ifndef CHERRYGUITKICONTROLLISTENER_H_
#define CHERRYGUITKICONTROLLISTENER_H_

#include <cherryMacros.h>
#include <cherryMessage.h>

#include "../cherryUiDll.h"
#include "cherryGuiTkControlEvent.h"

namespace cherry
{

namespace GuiTk
{

/**
 * Classes which implement this interface provide methods
 * that deal with the events that are generated by moving
 * and resizing controls.
 * <p>
 * After creating an instance of a class that implements
 * this interface it can be added to a control using the
 * <code>addControlListener</code> method and removed using
 * the <code>removeControlListener</code> method. When a
 * control is moved or resized, the appropriate method will
 * be invoked.
 * </p>
 *
 * @see ControlAdapter
 * @see ControlEvent
 */
struct CHERRY_UI IControlListener: public virtual Object
{

  cherryClassMacro(IControlListener);

  struct Events {

    typedef Message1<ControlEvent::Pointer> EventType;

    EventType movedEvent;
    EventType resizedEvent;
    EventType activatedEvent;

    void AddListener(IControlListener::Pointer listener);
    void RemoveListener(IControlListener::Pointer listener);

  private:
    typedef MessageDelegate1<IControlListener, ControlEvent::Pointer> Delegate;
  };

  virtual ~IControlListener()
  {
  }

  /**
   * Sent when the location (x, y) of a control changes relative
   * to its parent (or relative to the display, for <code>Shell</code>s).
   *
   * @param e an event containing information about the move
   */
  virtual void ControlMoved(ControlEvent::Pointer e)
  {
  }

  /**
   * Sent when the size (width, height) of a control changes.
   *
   * @param e an event containing information about the resize
   */
  virtual void ControlResized(ControlEvent::Pointer e)
  {
  }

  virtual void ControlActivated(ControlEvent::Pointer e)
  {
  }
};

}

}

#endif /* CHERRYGUITKICONTROLLISTENER_H_ */
