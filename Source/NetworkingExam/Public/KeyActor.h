#pragma once

#include "CoreMinimal.h"
#include "KeyComponent.h"
#include "GameFramework/Actor.h"
#include "KeyActor.generated.h"

/*
  This is a base class for all the Key BP I'll use

  Functionalities:
	- has a KeyComponent
	- has a Server Reliable function that calls the OnKeyLocked event on the KeyComponent
	- has a Server Reliable function that calls the OnKeyUnlocked event on the KeyComponent
*/

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom))
class NETWORKINGEXAM_API AKeyActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UKeyComponent* KeyComponent;

protected:
	virtual void BeginPlay() override;
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_UnlockKey();
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_LockKey();
public:
	AKeyActor();
};
