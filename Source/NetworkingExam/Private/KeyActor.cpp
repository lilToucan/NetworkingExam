#include "Public/KeyActor.h"


AKeyActor::AKeyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	KeyComponent = CreateDefaultSubobject<UKeyComponent>(TEXT("KeyComponent"));
}

void AKeyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKeyActor::Server_LockKey_Implementation()
{
	KeyComponent->OnKeyLock.Broadcast(KeyComponent);
}

void AKeyActor::Server_UnlockKey_Implementation()
{
	KeyComponent->OnKeyUnLock.Broadcast(KeyComponent);
}
