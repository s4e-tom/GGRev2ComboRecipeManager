#include "stdafx.h"
#include <msclr\auto_gcroot.h>
#using "GGRev2ComboRecipeManager.Lib.dll"
#include "ComboRecipeWrapper.h"

using byte = unsigned char;
using namespace System::Runtime::InteropServices; // Marshal

class ComboRecipeWrapperPrivate
{
public: msclr::auto_gcroot<GGRev2ComboRecipeManager::Lib::Models::ComboRecipe^> comboRecipe;
};

ComboRecipeWrapper::ComboRecipeWrapper(byte* comboData, int slotNr)
{
	//TODO: construct the unmanaged ComboRecipeWrapper (aka native cpp ComboRecipe)
	// here

	array<unsigned char, 1>^ managedBuffer = gcnew array<unsigned char>(SLOT_DATA_SIZE + SLOT_CHARCODE_SIZE);
	Marshal::Copy((System::IntPtr)comboData, managedBuffer, 0, SLOT_DATA_SIZE + SLOT_CHARCODE_SIZE);
	_private = new ComboRecipeWrapperPrivate();
	_private->comboRecipe = gcnew GGRev2ComboRecipeManager::Lib::Models::ComboRecipe(managedBuffer, slotNr);
}

ComboRecipeWrapper::~ComboRecipeWrapper()
{
	delete _private;
}

byte* ComboRecipeWrapper::ToRecipeData() {
	array<unsigned char, 1>^ nativeBuffer = _private->comboRecipe->ToRecipeData();
	pin_ptr<byte> tmp = &nativeBuffer[0];
	return reinterpret_cast<byte*>(tmp);
}