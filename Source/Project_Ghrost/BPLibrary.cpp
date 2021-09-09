


#include "BPLibrary.h"
#include "EngineUtils.h"

float UBPLibrary::SquareNumber(const float In) {
	return FMath::Pow(In, 2);
}

void UBPLibrary::TestFunction(float player) {
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

void UBPLibrary::AddHiddenActor(APlayerController* playerController, AActor* actorToHide) {
	playerController->HiddenActors.Add(actorToHide);
	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Some variable values: x: %d"), playerController->HiddenActors.Num()));
}

void UBPLibrary::RemoveHiddenActor(APlayerController* playerController, AActor* actorToUnhide) {
	playerController->HiddenActors.Remove(actorToUnhide);
}