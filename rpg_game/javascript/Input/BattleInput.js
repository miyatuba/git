class BattleInput {
    constructor()
    {
        this.is_input_party1 = false;
        this.is_input_party2 = false;
        this.is_input_party3 = false;
        this.is_input_party4 = false;
        this.is_input_party5 = false;
        this.is_input_party6 = false;
        this.is_input_party7 = false;
        this.is_input_party8 = false;


        this.test = false;
    }

    //���؃��\�b�h�Ȃ̂ŁA�����������ď���
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

    setParty1(rect)
    {
        var instatnce = this;
        rect.addEventListener("click", function () {
            handleParty1Click();
        });
        function handleParty1Click() {
            alert("�\���W���[���N���b�N����܂���");
            instatnce.is_input_party1 = true;
        }
    }

    isInputParty1()
    {
        return this.is_input_party1;
    }

    setParty2(rect) {
        var instatnce = this;
        rect.addEventListener("click", function () {
            handleParty2Click();
        });
        function handleParty2Click() {
            alert("�����T�[���N���b�N����܂���");
            instatnce.is_input_party2 = true;
        }
    }

    isInputParty2() {
        return this.is_input_party2;
    }

    setParty3(rect) {
        var instatnce = this;
        rect.addEventListener("click", function () {
            handleParty3Click();
        });
        function handleParty3Click() {
            alert("�A�[�`���[���N���b�N����܂���");
            instatnce.is_input_party3 = true;
        }
    }

    isInputParty3() {
        return this.is_input_party3;
    }

    setParty4(rect) {
        var instatnce = this;
        rect.addEventListener("click", function () {
            handleParty4Click();
        });
        function handleParty4Click() {
            alert("���C�W���N���b�N����܂���");
            instatnce.is_input_party4 = true;
        }
    }

    isInputParty4() {
        return this.is_input_party4;
    }

    setParty5(rect) {
        var instatnce = this;
        rect.addEventListener("click", function () {
            handleParty5Click();
        });
        function handleParty5Click() {
            alert("�N�����b�N���N���b�N����܂���");
            instatnce.is_input_party5 = true;
        }
    }

    isInputParty5() {
        return this.is_input_party5;
    }

    setParty6(rect) {
        var instatnce = this;
        rect.addEventListener("click", function () {
            handleParty6Click();
        });
        function handleParty6Click() {
            alert("���[�N���N���b�N����܂���");
            instatnce.is_input_party6 = true;
        }
    }

    isInputParty6() {
        return this.is_input_party6;
    }

    setParty7(rect) {
        var instatnce = this;
        rect.addEventListener("click", function () {
            handleParty7Click();
        });
        function handleParty7Click() {
            alert("�x���Z���N���N���b�N����܂���");
            instatnce.is_input_party7 = true;
        }
    }

    isInputParty7() {
        return this.is_input_party7;
    }

    setParty8(rect) {
        var instatnce = this;
        rect.addEventListener("click", function () {
            handleParty8Click();
        });
        function handleParty8Click() {
            alert("�n���^�[���N���b�N����܂���");
            instatnce.is_input_party8 = true;
        }
    }

    isInputParty8() {
        return this.is_input_party8;
    }

    resetForLoop()
    {
        this.is_input_party1 = false;
        this.is_input_party2 = false;
        this.is_input_party3 = false;
        this.is_input_party4 = false;
        this.is_input_party5 = false;
        this.is_input_party6 = false;
        this.is_input_party7 = false;
        this.is_input_party8 = false;
    }

}