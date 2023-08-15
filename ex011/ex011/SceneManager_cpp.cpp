#include "SceneManager.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

/*************

*�}�N����`

**************/

/*************

*�^��`

**************/

/************

*�ϐ��錾

************/

GAME_MODE Game_Mode;   //�Q�[�����[�h���i���݁j
GAME_MODE Next_Mode;   //�Q�[�����[�h���i���j



/*************

*�v���g�^�C�v�錾

**************/


/***************

*�V�[���Ǘ��@�\�F����������
* �����F�Ȃ�
*�߂�l�F�Ȃ�
****************/

int SceneManager_Initialize(GAME_MODE mode)

{

int Read_Error;

//�V�[���ǂݍ��ݏ���
//�^�C�g�����
Read_Error = TitleScene_Initialize();
if (Read_Error == D_ERROR)

{

 return D_ERROR;
}

//�Q�[�����C�����
Read_Error = GamemainScene_Initialize();
if (Read_Error == D_ERROR)

{

	return D_ERROR;

}

//�Q�[���N���A���
Read_Error = GameClearScene_Initialize();
if (Read_Error == D_ERROR)
{

	return D_ERROR;

}

//�Q�[���I�[�o�[���

Read_Error = GameOverScene_Initialize();
if (Read_Error == D_ERROR)

{

	return D_ERROR;

}

Game_Mode = mode;
Next_Mode = Game_Mode;

return Read_Error;

}

/********************

*�V�[���Ǘ��@�\�F�X�V����
* �����F�Ȃ�
* �߂�l�F�Ȃ�

*********************/

void Scenemanager_Updata(void)

{

//�O�t���[���ƃQ�[�����[�h������Ă�����V�[����؂�ւ���
	if (Game_Mode != Next_Mode)

{

		SceneManager_Initialize(Next_Mode);

}
	//�e��ʂ̍X�V����

	switch (Game_Mode)
	{

		case E_TITLE:
		TitleScene_Updata();
		break;

		case E_GAMEMAIN:
		GameMainScene_Updata();
		break;

		case E_GAME_CLEAR:
		GameClearScene_Updata();
		break;

		case E_GAME_OVER:
		GameOverScene_Updata();
		break;

		default:
			break;
	}
}

/*********************

*�V�[���Ǘ��@�\
* �����F�Ȃ�
* �߂�l�F�Ȃ�

***********************/

void SceneManager_Draw(void)
{

	//�e��ʂ̕`�揈��
	switch (Game_Mode)
	{

case E_TITLE:
			TitleScene_Updata();
			break;

	case E_GAMEMAIN:
			GameMainScene_Updata();
			break;

	case E_GAME_CLEAR:
			GameClearScene_Updata();
			break;

	case E_GAME_OVER:
			GameOverScene_Updata();
			break;

	default:
			break;

	}

}

/*******************

*�V�[���Ǘ��@�\�F�V�[���ؑ֏���
* �����F�ύX����Q�[�����[�h
* �߂�l�F�Ȃ�

*******************/

void Change_Scene(GAME_MODE mode)

{

	Next_Mode = mode;
}