#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "KeyComponent.generated.h"

/*
  this class works in conjunction with ULockComponent

  functionalities:
	- the BP that uses this component will call the OnKeyLocked and OnKeyUnlocked events when it wants
	- this will then call a function on any connected LockComponent
	- if all keys connected to said component have called the Unlock event then the Lock will unlock
	- if at least one key connected to the component calls the Lock event then the Lock will Lock again
*/

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeyUsed, UKeyComponent*, key);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class NETWORKINGEXAM_API UKeyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="KeyComponent")
	bool bHasBeenUsed = false;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, Category="KeyComponent")
	FOnKeyUsed OnKeyUnLock;
	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, Category="KeyComponent")
	FOnKeyUsed OnKeyLock;
};
