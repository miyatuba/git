using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MainSystem : MonoBehaviour
{
    public GameObject card_shuffle_serivce;

    // Start is called before the first frame update
    void Start()
    {
        card_shuffle_serivce.GetComponent<CardShuffleService>().Execute();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
