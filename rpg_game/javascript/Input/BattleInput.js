class BattleInput {
    constructor()
    {

    }

    setTest(rect)
    {
        // 各種マウスイベントを登録する
        rect.addEventListener("click", handleRectClick);
        // クリックしたとき
        function handleRectClick(event) {
            alert("四角形がクリックされました");
        }
    }
}