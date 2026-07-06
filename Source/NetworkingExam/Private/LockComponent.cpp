#include "NetworkingExam/Public/LockComponent.h"

ULockComponent::ULockComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULockComponent::BeginPlay()
{
	Super::BeginPlay();
	// gets all the key components out of the actors and binds to their events 
	for (AActor* Actor : KeyActors)
	{
		UKeyComponent* KeyComp = Actor->GetComponentByClass<UKeyComponent>();

		if (!KeyComp)
			continue;
		
		KeyComp->OnKeyUnLock.AddUniqueDynamic(this, &ULockComponent::KeyUnlock);
		KeyComp->OnKeyLock.AddUniqueDynamic(this, &ULockComponent::KeyLock);
		NumOfKeys++;
	}
}

void ULockComponent::KeyUnlock(UKeyComponent* Key)
{
	if (Key->bHasBeenUsed) // if it has already been activated
		return;
	
	NumOfKeysUsed++;
	if (NumOfKeysUsed >= NumOfKeys)
	{
		OnUnlocked.Broadcast();
		Key->bHasBeenUsed = true;
	}
}

void ULockComponent::KeyLock(UKeyComponent* Key)
{
	if (!Key->bHasBeenUsed) // if it hasn't even been activated yet
		return;
	
	NumOfKeysUsed--;
	if (NumOfKeysUsed < NumOfKeys)
	{
		OnLocked.Broadcast();
		Key->bHasBeenUsed = false;
	}
}
