class BattleInput {
    constructor()
    {
        this.inputParty1 = false;
        this.test = false;
    }

    setTest(rect)
    {
        // �e��}�E�X�C�x���g��o�^����
        /*rect.addEventListener("click", handleRectClick);
        // �N���b�N�����Ƃ�
        function handleRectClick(event) {
            alert("�l�p�`���N���b�N����܂���");
            this.test = true;
        }*/

        var instance = this;

        rect.addEventListener("click", function () {
            handleRectClick();
        });
        function handleRectClick() {
            alert("�l�p�`���N���b�N����܂���");
            instance.test = true;
        };

    }

    setParty1(rect1)
    {
        var instatnce = this;
        rect1.addEventListener("click", function () {
            handleParty1Click();
        });
        function handleParty1Click() {
            alert("�\���W���[���N���b�N����܂���");
            instatnce.inputParty1 = true;
        }

    }

    inputResetForLoop()
    {
        this.inputParty1 = false;
    }

}