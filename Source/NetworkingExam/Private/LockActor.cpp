#include "Public/LockActor.h"

#include "Net/UnrealNetwork.h"

ALockActor::ALockActor()
{
	PrimaryActorTick.bCanEverTick = true;
	bIsUnlocked = false;
	bReplicates = true;
	LockComponent = CreateDefaultSubobject<ULockComponent>(TEXT("KeyComponent"));
	LockComponent->OnLocked.AddUniqueDynamic(this,&ALockActor::Lock);
	LockComponent->OnUnlocked.AddUniqueDynamic(this,&ALockActor::Unlock);
}

void ALockActor::BeginPlay()
{
	Super::BeginPlay();
}

void ALockActor::Unlock_Implementation()
{
	bIsUnlocked = true;
}

void ALockActor::Lock_Implementation()
{
	bIsUnlocked = false;
}

void ALockActor::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALockActor, bIsUnlocked);
}
