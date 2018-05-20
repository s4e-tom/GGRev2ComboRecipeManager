#pragma once
#include <vector>
#include "ComboRecipeWrapper.h"

class ComboRecipeManagerWrapperPrivate;

public class _declspec(dllexport) ComboRecipeManagerWrapper
{
	private: ComboRecipeManagerWrapperPrivate* _private;
	public:	ComboRecipeManagerWrapper();
	public:	~ComboRecipeManagerWrapper();
	public: std::vector<ComboRecipeWrapper> ReadComboRecipes();
	public: void WriteRecipe(ComboRecipeWrapper recipe, int slotNr = 0);
};

