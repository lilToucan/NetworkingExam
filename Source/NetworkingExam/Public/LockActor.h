#pragma once

#include "CoreMinimal.h"
#include "LockComponent.h"
#include "GameFramework/Actor.h"
#include "LockActor.generated.h"

/*
  This is a base class for all the Lock BP I'll use

  Functionalities:
	- has a NetMulticast function called NetMulticast_ChangeLockState that is called when the lock is Locked or Unlocked by an attached key
	- said function then activates the BlueprintNativeEvent OnLockChangedState that will be implemented in the child BP
*/

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom))
class NETWORKINGEXAM_API ALockActor : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ULockComponent* LockComponent;

public:
	ALockActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(NetMulticast, Reliable)
	void NetMulticast_ChangeLockState(bool bIsUnlocked);
	
	UFUNCTION(BlueprintNativeEvent)
	void OnLockChangedState(bool bIsUnlocked);
	
	// called when the lock component has been locked 
	UFUNCTION()
	void Lock();
	// called when the lock component has been unlocked
	UFUNCTION()
	void Unlock();
	
};
