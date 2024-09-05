// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Interface/GameModeInterface.h"

#include "MarioGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API AMarioGameModeBase : public AGameModeBase , public IGameModeInterface
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ULifeWidget> LifeWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UStartWidget> StartWidget;

	virtual void MinusLife(int32 point) override;
	virtual void GameOver() override;
	virtual void BeginPlay() override;

	int32 currentLife = 1;

	// ���� �� ��Ʈ�� �ε�� ���� ����� ����
	UPROPERTY()
	class ULifeWidget* LifeUI;
	UPROPERTY()
	class UStartWidget* StartUI;

	void PrintLife();

	// Ÿ�̸� �ڵ�
	FTimerHandle RestartTimerHandle;

	void HideUIAndRestart(); // UI ����� ������ ������ϴ� �Լ�
};