//���C���[����
//create.js�ł́A�����Ƃ��ɂ���ƁA���씻��܂ŏ����Ă��܂��B���씻�肪�Ȃ��摜�ŏ㏑�����镪�ɂ͔��肪�����Ȃ����߂ɁA�ȉ��̂悤�ɑΉ�����K�v������
//�����蔻�背�C���[���ɕ`�恨�w�i�`�恨�L������G�t�F�N�g�Ȃǂ̕`��B

class Draw
{
    constructor()
    {
        this.stageCreateJS = new createjs.Stage("maincanvas0");
    }

    DrawBmp(bmp, x, y)
    {
        bmp.x = x;
        bmp.y = y;
        this.stageCreateJS.addChild(bmp);
    }

    updateStageCreateJS()
    {
        this.stageCreateJS.update();
    }
}

