// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibrary/NBAssetManagerFunctionLibrary.h"

UObject* UNBAssetManagerFunctionLibrary::SyncLoadObject(UObject* WorldObjectContext, const FSoftObjectPath& Path)
{
	return SynLoad<UObject>(WorldObjectContext, Path);
}
