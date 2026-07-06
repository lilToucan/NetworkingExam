#pragma once

#include "CoreMinimal.h"
#include "LockComponent.h"
#include "GameFramework/Actor.h"
#include "LockActor.generated.h"

/*
  This is a base class for all the Lock BP I'll use

  Functionalities:
	- has a replicated bool to know if it has been Open or not
	- has a LockComponent attached
	- connects to the LockedComponent's OnLocked and OnUnlocked events
*/

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom))
class NETWORKINGEXAM_API ALockActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Replicated)
	bool bIsUnlocked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ULockComponent* LockComponent;

public:
	ALockActor();

protected:
	UFUNCTION(BlueprintNativeEvent)
	void Unlock();
	UFUNCTION(BlueprintNativeEvent)
	void Lock();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void BeginPlay() override;
};
