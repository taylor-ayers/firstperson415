// Fill out your copyright notice in the Description page of Project Settings.


#include "Dust.h"
#include "firstperson415Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

// Sets default values
ADust::ADust()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>("Box Component");

	RootComponent = boxComp;

}

// Called when the game starts or when spawned
void ADust::BeginPlay()
{
	Super::BeginPlay();
	
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ADust::OnOverlapBegin);
	
}

// Called every frame
void ADust::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADust::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Afirstperson415Character* overlappedActor = Cast<Afirstperson415Character>(OtherActor);

	if (overlappedActor)
	{
		randColor = FLinearColor(UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), 1.f);
		// Spawn and Attach particle system to object and set color to parameter if niagara component is valid
		if (colorP)
		{
			UNiagaraComponent* particleComp = UNiagaraFunctionLibrary::SpawnSystemAttached(colorP, OtherComp, NAME_None, FVector(0.f), FRotator(0.f), EAttachLocation::KeepRelativeOffset, true);

			particleComp->SetNiagaraVariableLinearColor(FString("ParticleColor"), randColor);
		}
	}
}

