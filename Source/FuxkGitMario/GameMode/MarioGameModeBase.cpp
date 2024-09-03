// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "UI/LifeWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void AMarioGameModeBase::MinusLife(int32 point)
{
	currentLife -= point;

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

			UGameplayStatics::SetGamePaused(GetWorld(), true); // ���� ����
		}
	}
}