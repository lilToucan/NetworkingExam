#pragma once

#include "CoreMinimal.h"
#include "KeyComponent.h"
#include "Components/ActorComponent.h"
#include "LockComponent.generated.h"

/*
 this class works in conjunction with UKeyComponent

 functionalities:
	- gets all the key components out of the KeyActors list
	- then connects itself to the component's OnKeyLocked and OnKeyUnlocked events
	- when all the keys have used their unlock event the lock will call it's unlocked event
	- if one of the keys uses their lock event then the lock will call it's locked event
	- the BP that uses this component will have to bind to the OnLocked and OnUnlocked events
*/

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLockStateChanged);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class NETWORKINGEXAM_API ULockComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LockComponent|Config")
	TArray<AActor*> KeyActors;


	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="LockComponent")
	FLockStateChanged OnLocked;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="LockComponent")
	FLockStateChanged OnUnlocked;

protected:
	UPROPERTY(BlueprintReadWrite, Category="LockComponent")
	int NumOfKeys;

	UPROPERTY(BlueprintReadWrite, Category="LockComponent")
	int NumOfKeysUsed;

public:
	ULockComponent();

protected:
	UFUNCTION(BlueprintCallable)
	void KeyUnlock(UKeyComponent* Key);
	UFUNCTION(BlueprintCallable)
	void KeyLock(UKeyComponent* Key);
	virtual void BeginPlay() override;
};
