

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPLibrary.generated.h"

/**
 *
 */
UCLASS()
class PROJECT_GHROST_API UBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable)
		static float SquareNumber(const float In);
		UFUNCTION(BlueprintCallable)
		static void TestFunction(const float player);
		UFUNCTION(BlueprintCallable)
		static void AddHiddenActor(APlayerController* playerController, AActor* actorToHide);
		UFUNCTION(BlueprintCallable)
		static void RemoveHiddenActor(APlayerController* playerController, AActor* actorToUnhide);
};
