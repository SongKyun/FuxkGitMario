// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Block.h"

#include "Components/BoxComponent.h"

void ATrap_Block::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_Block::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATrap_Block::ActiveTrap(AActor* Player)
{
	Super::ActiveTrap(Player);
	UE_LOG(LogTemp, Warning, TEXT("Trap Block Active Trap"));
	FVector PlayerUpVector = Player->GetActorUpVector(); // Player�� UpVector��������
	FVector ImpactDir = GetActorLocation() - Player->GetActorLocation(); // Player -> Trap�� ���⺤��
	ImpactDir.Normalize();

	float DotProduct = FVector::DotProduct(PlayerUpVector, ImpactDir); // (0,0,1) ���Ϳ� ���⺤���� ������
	//UE_LOG(LogTemp, Warning, TEXT("DotProduct_PlayerUpVector-ImpactDir : %.2f"), DotProduct);

	if(DotProduct > 0.5f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Success DotProduct > 0.5f"));
		//FVector ForwardVector = Player->GetActorForwardVector(); // Player�� �չ��� ����
		FVector ForwardVector = Player->GetActorRightVector(); // Player�� �չ��� ����
		//float DotProduct11 = FVector::DotProduct(ImpactDir, ForwardVector);
		float Angle = FMath::Acos(FVector::DotProduct(ImpactDir, ForwardVector)); // (0,1,0) ���Ϳ� ���⺤���� ������ ACos�� Radian��
		//UE_LOG(LogTemp, Warning, TEXT("Player's ForwardVector x : %.2f, y : %.2f, z : %.2f"), ForwardVector.X, ForwardVector.Y, ForwardVector.Z);
		//UE_LOG(LogTemp, Warning, TEXT("DotProduct11_ImpactDir-ForwardVector : %.2f"), DotProduct11);
		//UE_LOG(LogTemp, Warning, TEXT("Angle_ImpactDir-ForwardVector : %.2f"), Angle);

		float AngleDegrees = FMath::RadiansToDegrees(Angle); // Radian�� degree������ ����
		//UE_LOG(LogTemp, Warning, TEXT("AngleDegrees : %.2f"), AngleDegrees);
		if(AngleDegrees >= 15.0f) // �÷��̾� �չ���� ���⺤���� ���̰��� 15�� �̻��̸� (������ �������� �Ȱ� �ƴ϶��..?)
		{
			// Trap Activation
			UE_LOG(LogTemp, Warning, TEXT("Success AngleDegree <= 15.0f"));
			BoxComp->SetCollisionResponseToChannel(ECC_EngineTraceChannel1, ECR_Block); // CollisionChannel�� Block���� ����
			MeshComp->SetMaterial(0, ExposeMat); // Material ����
		}
	}
}

