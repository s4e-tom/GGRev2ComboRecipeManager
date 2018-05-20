#include "stdafx.h"
#include <msclr\auto_gcroot.h>
#using "GGRev2ComboRecipeManager.Lib.dll"
#include "ComboRecipeManagerWrapper.h"

using namespace System::Runtime::InteropServices; // Marshal

class ComboRecipeManagerWrapperPrivate
{
public: msclr::auto_gcroot<GGRev2ComboRecipeManager::Lib::ComboRecipeManager^> comboRecipeManager;
};

ComboRecipeManagerWrapper::ComboRecipeManagerWrapper()
{
	_private = new ComboRecipeManagerWrapperPrivate();
	_private->comboRecipeManager = gcnew GGRev2ComboRecipeManager::Lib::ComboRecipeManager();
}

std::vector<ComboRecipeWrapper> ComboRecipeManagerWrapper::ReadComboRecipes() {
	array<GGRev2ComboRecipeManager::Lib::Models::ComboRecipe^, 1>^ managedArray = _private->comboRecipeManager->ReadComboRecipes();

	for each (GGRev2ComboRecipeManager::Lib::Models::ComboRecipe^ c in managedArray)
	{
		//todo: convert the ComboRecipe^ (managed) to ComboRecipeWrapper (unmanaged) and push it into a vector
		// make a copy constructor ComboRecipeWrapper(ComboRecipe^ c)?
	}
}
