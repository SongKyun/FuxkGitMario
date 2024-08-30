// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TrapInterface.h"
#include "GameFramework/Actor.h"
#include "TrapBase.generated.h"

UCLASS()
class FUXKGITMARIO_API ATrapBase : public AActor, public ITrapInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrapBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool bIsActive;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void ActiveTrap(AActor* Player) override;

	UPROPERTY(EditAnywhere, Category = "Trap")
	class UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditAnywhere, Category = "Trap")
	class UBoxComponent* BoxComp;

	UFUNCTION()
	void OnTrapOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult & SweepResult);
private:
};
