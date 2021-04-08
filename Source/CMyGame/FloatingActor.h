// Fill out your copyright notice in the Description page of Project Settings.

/*
* 编程快速入门
* 创建首个代码项目，并添加新的C++类。
* https://docs.unrealengine.com/zh-CN/ProgrammingAndScripting/ProgrammingWithCPP/CPPProgrammingQuickStart/index.html
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"


UCLASS()
class CMYGAME_API AFloatingActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFloatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float RunningTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor");
	float FloatSpeed = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor");
	float RotationSpeed = 20.0f;

	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(VisibleAnywhere);
	UParticleSystemComponent* OurParticleComponent;


};
