class BaseAbility
{

    //方法に悩む
    //1.Baseを作ってAbility毎に継承手法で作る方法
    //2.idを渡してインスタンスを作り、各abilityの処理をする方法
    //3.ほとんど2の方法。これをジョブごとで作成する
    //4.3の方法を継承で行う。
    //ジョブごとで完全にabilityが完全に違うならジョブごと、否なら1つずつ作った方が無難だと思う
    //abilityの数が比較的に少ないのであればid渡し型で良いと思う。
    //よって、今回は1で行こう
    constructor()
    {
        this.name;
        this.type;
        this.value;
        this.useJob;
    }
}