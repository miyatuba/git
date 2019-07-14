class BattleInput {
    constructor()
    {
        this.inputParty1 = false;
        this.test = false;
    }

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

    setParty1(rect1)
    {
        var instatnce = this;
        rect1.addEventListener("click", function () {
            handleParty1Click();
        });
        function handleParty1Click() {
            alert("ソルジャーがクリックされました");
            instatnce.inputParty1 = true;
        }

    }

    inputResetForLoop()
    {
        this.inputParty1 = false;
    }

}