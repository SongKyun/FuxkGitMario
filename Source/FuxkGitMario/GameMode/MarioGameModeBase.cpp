// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "UI/LifeWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/Character.h"
#include "GameMode/MarioGameInstance.h"
#include "EngineUtils.h"
#include "UI/StartWidget.h"

void AMarioGameModeBase::MinusLife(int32 point)
{
	currentLife -= point;

}

void AMarioGameModeBase::StartGame()
{
	if (StartUI)
	{
		StartUI->ChangeUIToStart();
	}
}

void AMarioGameModeBase::PrintLife()
{
	if (LifeUI != nullptr)
	{
		// LifeData �ؽ�Ʈ ��Ͽ� ���� ���� ���� �Է�
		LifeUI->LifeData->SetText(FText::AsNumber(currentLife));
	}
}

void AMarioGameModeBase::GameOver()
{
	if (LifeWidget != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Over"));

		MinusLife(1);

		// �������Ʈ ������ �޸𸮿� �ε��Ѵ�.
		LifeUI = CreateWidget<ULifeWidget>(GetWorld(), LifeWidget);

		PrintLife();

		// �޸𸮿� �ε� �� �� ��Ʈ�� ���
		if (LifeUI != nullptr)
		{
			LifeUI->AddToViewport();

			//UGameplayStatics::SetGamePaused(GetWorld(), true); // ���� ����

			// ���� �����
			// 3�� �Ŀ� HideUIAndRestart �Լ��� ȣ���ϵ��� Ÿ�̸� ����
			GetWorld()->GetTimerManager().SetTimer(RestartTimerHandle, this, &AMarioGameModeBase::HideUIAndRestart, 3.0f, false);
		}
	}
}

void AMarioGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	MarioInstance = Cast<UMarioGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MarioInstance)
	{
		currentLife = MarioInstance->LoadLife();
	}
	if (currentLife > 0)
	{
		StartUI = CreateWidget<UStartWidget>(GetWorld(), StartWidget);
		if (StartUI)
		{
			StartUI->AddToViewport();
		}

		// �Է¸�带 UI �� �������ֱ�
		//GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	}
}

void AMarioGameModeBase::HideUIAndRestart()
{
	// UI�� �����մϴ�.
	if (LifeUI != nullptr)
	{
		LifeUI->RemoveFromViewport();
		LifeUI = nullptr;
	}
	if (MarioInstance)
	{
		MarioInstance->SaveLife(currentLife);
	}
	UE_LOG(LogTemp, Warning, TEXT("Game Resumed!"));
	UGameplayStatics::OpenLevel(this, FName("MapTestStage"));
}