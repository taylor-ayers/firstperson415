// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CubeDMIMod.generated.h"

UCLASS()
class FIRSTPERSON415_API ACubeDMIMod : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeDMIMod();

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Adds components/properities to Object and sets to editable
	UPROPERTY(EditAnywhere)
		UBoxComponent* boxComp;
	
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* cubeMesh;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* baseMat;

	UPROPERTY()
		UMaterialInstanceDynamic* dmiMat;

	// Overlap event
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
