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
        FVector CurrentLocation = GetActorLocation();

        // X ��ǥ�� �ӵ��� ���� ������ŵ�ϴ�.
        float Speed = 1000.0f; // X�� �̵� �ӵ�
        CurrentLocation.Z += Speed * DeltaTime;

        // Y ��ǥ�� ������ ���·� �����մϴ�.
        float Amplitude = 700.0f; // �������� ����
        float Frequency = 2.0f; // �������� ���ļ�
        float Time = GetWorld()->GetTimeSeconds(); // ��� �ð�
        CurrentLocation.Z = Amplitude * FMath::Sin(Frequency * Time);

        // ���ο� ��ġ�� �����մϴ�.
        SetActorLocation(CurrentLocation);
	}
}

void ATrap_UpDown::ActiveTrap(AActor* Player)
{
	IsActiveTrap = true;
}