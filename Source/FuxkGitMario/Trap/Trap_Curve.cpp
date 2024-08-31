// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Curve.h"

void ATrap_Curve::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_Curve::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (IsActiveTrap)
    {
        FVector CurrentLocation = GetActorLocation();

        // X ��ǥ�� �ӵ��� ���� ������ŵ�ϴ�.
        float Speed = 1000.0f; // X�� �̵� �ӵ�
        CurrentLocation.Y -= Speed * DeltaTime;

        // Y ��ǥ�� ������ ���·� �����մϴ�.
        float Amplitude = 700.0f; // �������� ����
        float Frequency = 2.0f; // �������� ���ļ�
        float Time = GetWorld()->GetTimeSeconds(); // ��� �ð�
        CurrentLocation.Z = Amplitude * FMath::Sin(Frequency * Time);

        // ���ο� ��ġ�� �����մϴ�.
        SetActorLocation(CurrentLocation);
    }
}

void ATrap_Curve::ActiveTrap(AActor* Player)
{
    IsActiveTrap = true;
}
