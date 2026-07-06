#include "Public/LockActor.h"

#include "Net/UnrealNetwork.h"

ALockActor::ALockActor()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	LockComponent = CreateDefaultSubobject<ULockComponent>(TEXT("KeyComponent"));
	LockComponent->OnLocked.AddUniqueDynamic(this, &ALockActor::Lock);
	LockComponent->OnUnlocked.AddUniqueDynamic(this, &ALockActor::Unlock);
}

void ALockActor::BeginPlay()
{
	Super::BeginPlay();
}

void ALockActor::NetMulticast_ChangeLockState_Implementation(bool bIsUnlocked)
{
	OnLockChangedState(bIsUnlocked);
}

void ALockActor::OnLockChangedState_Implementation(bool bIsUnlocked)
{
}


void ALockActor::Unlock()
{
	NetMulticast_ChangeLockState(true);
}

void ALockActor::Lock()
{
	NetMulticast_ChangeLockState(false);
}
