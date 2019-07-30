using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class Entity : MonoBehaviour
{
    public GameObject create_zone_object;

    public EventSystem event_system;

    // Start is called before the first frame update
    void Start()
    {

        
    }

    // Update is called once per frame
    void Update()
    {
        //画像のクリック処理
        if (Input.GetMouseButtonUp(0)) {


            if (this.event_system.currentSelectedGameObject != null) {
                
                if (this.event_system.currentSelectedGameObject.name == "Entity") {
                    if (this.create_zone_object.activeSelf) {
                        this.create_zone_object.SetActive(false);
                    } else {
                        this.create_zone_object.SetActive(true);
                    }
                }

            }
        }

    }

}