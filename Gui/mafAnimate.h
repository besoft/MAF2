/*=========================================================================
  Program:   Multimod Application Framework
  Module:    $RCSfile: mafAnimate.h,v $
  Language:  C++
  Date:      $Date: 2006-01-30 11:46:54 $
  Version:   $Revision: 1.3 $
  Authors:   Paolo Quadrani
==========================================================================
  Copyright (c) 2002/2004
  CINECA - Interuniversity Consortium (www.cineca.it) 
=========================================================================*/

#ifndef __mafAnimate_H__
#define __mafAnimate_H__

#include "mafEvent.h"
#include "mafObserver.h"

class mafNode;
class mafTagArray;
class mmgButton;
class vtkRenderer;
class mmgGui;

//----------------------------------------------------------------------------
// mafAnimate :
//----------------------------------------------------------------------------
/**
This component allow to manage camera animation into a view.
mafAnimate allow to store and retrieve a particular point of view.
*/
class mafAnimate : public mafObserver
{
public:
	mafAnimate(vtkRenderer *renderer, mafNode *vme, mafObserver *listener = NULL);
	~mafAnimate(); 
	void OnEvent(mafEventBase *maf_event);
	void SetListener(mafObserver *listener) {m_Listener = listener;};

	/** Return mafAnimate User Interface */
	mmgGui *GetGui() {return m_Gui;};

  /** set the vme that hold the tagarray where the ViewPoint are stored */
	void SetInputVME(mafNode *vme);

	/** Read root node's tags to retrieve previous stored camera positions.  */
	void RetrieveStoredPositions();

  /** delete All entries in listbox.*/
  void ResetKit();

protected:
	/** Move the camera to the target position */
	void FlyTo();
  void FlyTo2(); /// silvano backup

	/** Store a view position into the root's tag array */
	void StoreViewPoint();

	/** Rename the view position */
	void RenameViewPoint();

	/** Delete the view position */
	void DeleteViewPoint();

	/** Create the GUI for the FlyTo animation */
	void CreateGui();

	/** Enable-Disable the GUI's widgets */
	void EnableWidgets();
	mafObserver	*m_Listener;

	mafTagArray		*m_Tags;
	vtkRenderer		*m_Renderer;
	mmgGui				*m_Gui;

	wxString			 m_SelectedPosition;
	wxListBox			*m_PositionList;
	mmgButton			*m_StorePositionButton; 
	mmgButton			*m_DeletePositionButton;
	mmgButton			*m_RenamePositionButton;
	int						 m_AnimateFlag;
};
#endif