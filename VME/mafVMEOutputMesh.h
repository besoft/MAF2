/*=========================================================================
  Program:   Multimod Application Framework
  Module:    $RCSfile: mafVMEOutputMesh.h,v $
  Language:  C++
  Date:      $Date: 2007-04-04 16:38:14 $
  Version:   $Revision: 1.1 $
  Authors:   Stefano Perticoni
==========================================================================
  Copyright (c) 2001/2005 
  CINECA - Interuniversity Consortium (www.cineca.it)
=========================================================================*/
#ifndef __mafVMEOutputMesh_h
#define __mafVMEOutputMesh_h
//----------------------------------------------------------------------------
// Include:
//----------------------------------------------------------------------------
#include "mafVMEOutputVTK.h"
//----------------------------------------------------------------------------
// forward declarations :
//----------------------------------------------------------------------------
class vtkUnstructuredGrid;

/** 
  mafVMEOutputMesh is the output produced by a node generating an output
  with a VTK unstructured grid dataset.
*/
class MAF_EXPORT mafVMEOutputMesh : public mafVMEOutputVTK
{
public:
  mafVMEOutputMesh();
  virtual ~mafVMEOutputMesh();

  mafTypeMacro(mafVMEOutputMesh,mafVMEOutputVTK);

  /**
    Return a VTK dataset corresponding to the current time. This is
    the output of the DataPipe currently attached to the VME.
    Usually the output is a  "smart copy" of one of the dataset in 
    the DataArray. In some cases it can be NULL, e.g. in case the number
    of stored Items is 0. Also special VME could not support VTK dataset output.
    An event is rised when the output data changes to allow attached classes to 
    update their input.*/
  virtual vtkUnstructuredGrid *GetUnstructuredGridData();

  /** Update all the output data structures (data, bounds, matrix and abs matrix).*/
  virtual void Update();

protected: 

  mafString  m_NumCells;
  mmgGui *CreateGui();

private:
  mafVMEOutputMesh(const mafVMEOutputMesh&); // Not implemented
  void operator=(const mafVMEOutputMesh&); // Not implemented
};

#endif