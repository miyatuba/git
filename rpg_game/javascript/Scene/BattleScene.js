class BattleScene {
    BATTLE_BACK_GRAUND_IMAGE = "resource/image/back_graund/back_ground1.jpg";

    PARTY_NUMBER_ID_SOLDIER = 1;
    PARTY_NUMBER_ID_LANCER = 2;
    PARTY_NUMBER_ID_ARCHER = 3;
    PARTY_NUMBER_ID_MAGE = 4;
    PARTY_NUMBER_ID_CLERIC = 5;
    PARTY_NUMBER_ID_ROOK = 6;
    PARTY_NUMBER_ID_BERSERK = 7;
    PARTY_NUMBER_ID_HUNTER = 8;

    constructor() {
        this.draw = new Draw();

        this._initPartyDeploy();
        this._initEnemyDeploy();

        var bmp_back_ground = new createjs.Bitmap(this.BATTLE_BACK_GRAUND_IMAGE);
        bmp_back_ground.scaleX = 1;
        bmp_back_ground.scaleY = 1;
        this.draw.DrawBmp(bmp_back_ground, 0, 0);
        this.draw.DrawBmp(this.party_character_position1.getBmp(), 450, 20);
        this.draw.DrawBmp(this.party_character_position1.getRectCollision(), 450, 20);
        this.draw.DrawBmp(this.party_character_position2.getBmp(), 450, 170);
        this.draw.DrawBmp(this.party_character_position2.getRectCollision(), 450, 170);
        this.draw.DrawBmp(this.party_character_position3.getBmp(), 570, 70);
        this.draw.DrawBmp(this.party_character_position3.getRectCollision(), 570, 70);
        this.draw.DrawBmp(this.party_character_position4.getBmp(), 570, 220);
        this.draw.DrawBmp(this.party_character_position4.getRectCollision(), 570, 220);
        this.draw.DrawBmp(this.party_character_position5.getBmp(), 700, 20);
        this.draw.DrawBmp(this.party_character_position5.getRectCollision(), 700, 20);
        this.draw.DrawBmp(this.party_character_position6.getBmp(), 700, 170);
        this.draw.DrawBmp(this.party_character_position6.getRectCollision(), 700, 170);
        this.draw.DrawBmp(this.party_character_position7.getBmp(), 820, 70);
        this.draw.DrawBmp(this.party_character_position7.getRectCollision(), 820, 70);
        this.draw.DrawBmp(this.party_character_position8.getBmp(), 820, 220);
        this.draw.DrawBmp(this.party_character_position8.getRectCollision(), 820, 220);
        this.draw.DrawBmp(this.enemy_character_position1.getBmp(), 200, 70);
        this.draw.DrawBmp(this.enemy_character_position2.getBmp(), 200, 220);
        this.draw.DrawBmp(this.enemy_character_position3.getBmp(), 100, 20);
        this.draw.DrawBmp(this.enemy_character_position4.getBmp(), 100, 170);
        this.draw.DrawBmp(this.enemy_character_position5.getBmp(), 0, 70);
        this.draw.DrawBmp(this.enemy_character_position6.getBmp(), 0, 220);
    }

    _initPartyDeploy() {
        this.party_character_position1 = new Soldier(false);
        this.party_character_position2 = new Lancer(false);
        this.party_character_position3 = new Archer(false);
        this.party_character_position4 = new Mage(false);
        this.party_character_position5 = new Cleric(false);
        this.party_character_position6 = new Rook(false);
        this.party_character_position7 = new Berserk(false);
        this.party_character_position8 = new Hunter(false);
        this.playable_party_id = this.PARTY_NUMBER_ID_BERSERK;
        this.playable_party_position_number = 7;
    }

    _initEnemyDeploy() {
        //多分idを渡してモンスターをインスタンス化するようなfactoryクラスが必要になる予感
        this.enemy_character_position1 = new Goblin;
        this.enemy_character_position2 = new Goblin;
        this.enemy_character_position3 = new Goblin;
        this.enemy_character_position4 = new Goblin;
        this.enemy_character_position5 = new Goblin;
        this.enemy_character_position6 = new Goblin;
    }

    play() {
        //入力処理

        console.log();
        //内部計算
        //表示

        this.draw.updateStageCreateJS();
    }

    input() {
        //メニューを開いたかどうか

        //入力処理（プレイアブル
        switch (this.playable_party_position_number) {
            case 1://流石にここはマジックナンバーで良いと思うんだけど・・
                this._inputPosition1();
                break;
            case 2:
                this._inputPosition2();
                break;
            case 3:
                this._inputPosition3();
                break;
            case 4:
                this._inputPosition4();
                break;
            case 5:
                this._inputPosition5();
                break;
            case 6:
                this._inputPosition6();
                break;
            case 7:
                this._inputPosition7();
                break;
            case 8:
                this._inputPosition8();
                break;
        }

        //味方CPの処理
        //敵CPの処理

        
    }

    _inputPosition1()
    {
        //戦闘可能かどうか
        //行動中か否かの確認
        //行動中であればアニメーションを進めてダメージ計算も進めてreturn
        //キャラタッチの確認
        //コマンドの確認
    }

    _inputPosition2()
    {

    }

    _inputPosition3()
    {

    }

    _inputPosition4()
    {

    }

    _inputPosition5()
    {

    }

    _inputPosition6()
    {

    }

    _inputPosition7()
    {
        //行動中か同課の確認
        //行動中であればアニメーションを進めてreturn
        //キャラタッチの確認
        var partyPosition1RectCollision = this.party_character_position1.getRectCollision();
        partyPosition1RectCollision.addEventListener("click", changePartyTarget1);
        function changePartyTarget1() {
            this.party_character_position1.changePartyTarget(1);
        }
        var partyPosition2RectCollision = this.party_character_position2.getRectCollision();
        partyPosition2RectCollision.addEventListener("click", changePartyTarget2);
        function changePartyTarget2() {
            this.party_character_position2.changePartyTarget(2);
        }
        var partyPosition3RectCollision = this.party_character_position3.getRectCollision();
        partyPosition3RectCollision.addEventListener("click", changePartyTarget3);
        function changePartyTarget3() {
            this.party_character_position3.changePartyTarget(3);
        }
        var partyPosition4RectCollision = this.party_character_position4.getRectCollision();
        partyPosition4RectCollision.addEventListener("click", changePartyTarget4);
        function changePartyTarget4() {
            this.party_character_position4.changePartyTarget(4);
        }
        var partyPosition5RectCollision = this.party_character_position5.getRectCollision();
        partyPosition5RectCollision.addEventListener("click", changePartyTarget5);
        function changePartyTarget5() {
            this.party_character_position5.changePartyTarget(5);
        }
        var partyPosition6RectCollision = this.party_character_position6.getRectCollision();
        partyPosition6RectCollision.addEventListener("click", changePartyTarget6);
        function changePartyTarget6() {
            this.party_character_position6.changePartyTarget(6);
        }
        var partyPosition7RectCollision = this.party_character_position7.getRectCollision();
        partyPosition7RectCollision.addEventListener("click", changePartyTarget7);
        function changePartyTarget7() {
            this.party_character_position7.changePartyTarget(7);
        }

        var partyPosition8RectCollision = this.party_character_position8.getRectCollision();
        partyPosition8RectCollision.addEventListener("click", changePartyTarget8);
        function changePartyTarget8() {
            this.party_character_position8.changePartyTarget(8);
        }
        //コマンドの確認
    }

    _inputPosition8()
    {

    }

    //positionNumberから判断してxとyを返す関数
}
