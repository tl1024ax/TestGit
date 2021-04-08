// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded()) {
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	// 添加粒子系统组件
	OurParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("OurParticleComponent"));
	OurParticleComponent->SetupAttachment(VisualMesh);
	OurParticleComponent->bAutoActivate = true;
	OurParticleComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 30.0f));
	OurParticleComponent->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
	//static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	if (ParticleAsset.Succeeded()) {
		OurParticleComponent->SetTemplate(ParticleAsset.Object);
	}
	//OurParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("OurParticleComponent"));

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	RunningTime = GetGameTimeSinceCreation();

	float DeltaHeight = (FMath::Sin((RunningTime + DeltaTime) * 2) - FMath::Sin(RunningTime * 2));
	NewLocation.Z += DeltaHeight * FloatSpeed;

	float DeltaRotation = DeltaTime * RotationSpeed;
	NewRotation.Yaw += DeltaRotation;

	SetActorLocationAndRotation(NewLocation, NewRotation);
}

