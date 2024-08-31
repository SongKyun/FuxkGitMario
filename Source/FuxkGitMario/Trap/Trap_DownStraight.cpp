// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_DownStraight.h"
#include "../Player/Player_Mario.h"

void ATrap_DownStraight::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_DownStraight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsActiveTrap)
	{
		if (not IsCollinear) Dir = FVector::DownVector; // �÷��̾�� ���ϼ����� �ƴ϶�� �Ʒ��θ� ��������
		
		// �÷��̾�� ���� �����̶��
		if (GetActorLocation().Z <= Target->GetActorLocation().Z)
		{
			Dir = -FVector::RightVector;
			Speed = 4500.0f;
			IsCollinear = true; // �÷��̾�� ���ϼ����� �ѹ��̶� ������ �׳� ������������ �� ���󰡰� �ϱ� ���� ���
		}

		FVector newLocation = GetActorLocation() + Dir * Speed * DeltaTime;
		SetActorLocation(newLocation);
	}
}

void ATrap_DownStraight::ActiveTrap(AActor* Player)
{
	IsActiveTrap = true;
	Target = Cast<APlayer_Mario>(Player);
}
