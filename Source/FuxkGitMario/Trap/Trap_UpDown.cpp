// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_UpDown.h"

void ATrap_UpDown::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_UpDown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsActiveTrap)
	{
        FVector currentLocation = GetActorLocation();
        Time += DeltaTime; // 0�������� �����ϰ� �ϱ� ���� �ð���
        // Z ��ǥ�� �ӵ��� ���� ������ŵ�ϴ�.
        //float Speed = 1000.0f; // Z�� �̵� �ӵ�
        //CurrentLocation.Z += Speed * DeltaTime;

        // Z ��ǥ�� �ڻ����� ���·� �����մϴ�.
        float amplitude = 1200.0f; // �ڻ������� ����
        float frequency = 3.5f; // �ڻ������� ���ļ�
        currentLocation.Z = amplitude * -FMath::Cos(frequency * Time);

        // ���ο� ��ġ�� �����մϴ�.
        SetActorLocation(currentLocation);
	}
}

void ATrap_UpDown::ActiveTrap(AActor* Player)
{
	IsActiveTrap = true;
}