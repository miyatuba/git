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

        this.is_input_enemy1 = false;
        this.is_input_enemy2 = false;
        this.is_input_enemy3 = false;
        this.is_input_enemy4 = false;
        this.is_input_enemy5 = false;
        this.is_input_enemy6 = false;

        this.test = false;
    }

    //検証メソッドなので、頃合いを見て消す
    setTest(rect)
    {
        // 各種マウスイベントを登録する
        /*rect.addEventListener("click", handleRectClick);
        // クリックしたとき
        function handleRectClick(event) {
            alert("四角形がクリックされました");
            this.test = true;
        }*/

        var instance = this;

        rect.addEventListener("click", function () {
            handleRectClick();
        });
        function handleRectClick() {
            alert("四角形がクリックされました");
            instance.test = true;
        };

    }

    setRectParty1(rect)
    {
        var instance = this;
        rect.addEventListener("click", function () {
            handleParty1Click();
        });
        function handleParty1Click() {
            //alert("ソルジャーがクリックされました");
            instance.is_input_party1 = true;
        }
    }

    isInputParty1()
    {
        return this.is_input_party1;
    }

    setRectParty2(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleParty2Click();
        });
        function handleParty2Click() {
            //alert("ランサーがクリックされました");
            instance.is_input_party2 = true;
        }
    }

    isInputParty2() {
        return this.is_input_party2;
    }

    setRectParty3(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleParty3Click();
        });
        function handleParty3Click() {
            //alert("アーチャーがクリックされました");
            instance.is_input_party3 = true;
        }
    }

    isInputParty3() {
        return this.is_input_party3;
    }

    setRectParty4(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleParty4Click();
        });
        function handleParty4Click() {
            //alert("メイジがクリックされました");
            instance.is_input_party4 = true;
        }
    }

    isInputParty4() {
        return this.is_input_party4;
    }

    setRectParty5(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleParty5Click();
        });
        function handleParty5Click() {
            //alert("クレリックがクリックされました");
            instance.is_input_party5 = true;
        }
    }

    isInputParty5() {
        return this.is_input_party5;
    }

    setRectParty6(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleParty6Click();
        });
        function handleParty6Click() {
            //alert("ルークがクリックされました");
            instance.is_input_party6 = true;
        }
    }

    isInputParty6() {
        return this.is_input_party6;
    }

    setRectParty7(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleParty7Click();
        });
        function handleParty7Click() {
            //alert("ベルセルクがクリックされました");
            instance.is_input_party7 = true;
        }
    }

    isInputParty7() {
        return this.is_input_party7;
    }

    setRectParty8(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleParty8Click();
        });
        function handleParty8Click() {
            //alert("ハンターがクリックされました");
            instance.is_input_party8 = true;
        }
    }

    isInputParty8() {
        return this.is_input_party8;
    }

    setRectEnemy1(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleEnemy1Click();
        });
        function handleEnemy1Click() {    
            instance.is_input_enemy1 = true;
        }
    }

    isInputEnemy1() {
        return this.is_input_enemy1;
    }

    setRectEnemy2(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleEnemy2Click();
        });
        function handleEnemy2Click() {
            instance.is_input_enemy2 = true;
        }
    }

    isInputEnemy2() {
        return this.is_input_enemy2;
    }

    setRectEnemy3(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleEnemy3Click();
        });
        function handleEnemy3Click() {
            instance.is_input_enemy3 = true;
        }
    }

    isInputEnemy3() {
        return this.is_input_enemy3;
    }

    setRectEnemy4(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleEnemy4Click();
        });
        function handleEnemy4Click() {
            instance.is_input_enemy4 = true;
        }
    }

    isInputEnemy4() {
        return this.is_input_enemy4;
    }

    setRectEnemy5(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleEnemy5Click();
        });
        function handleEnemy5Click() {
            instance.is_input_enemy5 = true;
        }
    }

    isInputEnemy5() {
        return this.is_input_enemy5;
    }

    setRectEnemy6(rect) {
        var instance = this;
        rect.addEventListener("click", function () {
            handleEnemy6Click();
        });
        function handleEnemy6Click() {
            instance.is_input_enemy6 = true;
        }
    }

    isInputEnemy6() {
        return this.is_input_enemy6;
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

        this.is_input_enemy1 = false;
        this.is_input_enemy2 = false;
        this.is_input_enemy3 = false;
        this.is_input_enemy4 = false;
        this.is_input_enemy5 = false;
        this.is_input_enemy6 = false;
    }

}