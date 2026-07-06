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
	if (Key->bHasBeenUsed) // if it has already been used to unlock the lock then don't use it again
		return;

	NumOfKeysUsed++;
	Key->bHasBeenUsed = true;

	// if the number of keys used is the same as the keys connected to the lock then Call the OnUnlocked Event
	if (NumOfKeysUsed >= NumOfKeys) 
	{
		OnUnlocked.Broadcast();
	}
}

void ULockComponent::KeyLock(UKeyComponent* Key)
{

	if (!Key->bHasBeenUsed) // if the key is already locked then don't lock it again 
		return;
	
	bool bHasLockBeenUnlocked = false; // check if the lock had been unlocked before 
	if (NumOfKeysUsed >= NumOfKeys)
		bHasLockBeenUnlocked = true;

	NumOfKeysUsed--;
	Key->bHasBeenUsed = false; // reset the use of the key so that it can unlock this lock again

	// if the lock has been unlocked before then call the OnLocked event otherwise it's already locked and doesn't need to lock again
	if (NumOfKeysUsed < NumOfKeys || bHasLockBeenUnlocked == true)
	{
		OnLocked.Broadcast();
	}
}
