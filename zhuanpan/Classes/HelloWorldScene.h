#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#define DISK_NAME ("disk.png")
#define POINT_NAME ("point.png")

#define ANGEL_REWARD0 (45)
#define ANGEL_REWARD1 (90)
#define ANGEL_REWARD2 (135)
#define ANGEL_REWARD3 (180)
#define ANGEL_REWARD4 (225)
#define ANGEL_REWARD5 (270)
#define ANGEL_REWARD6 (315)
#define ANGEL_REWARD7 (360)

#define REWARD0 ("A")
#define REWARD1 ("H")
#define REWARD2 ("G")
#define REWARD3 ("F")
#define REWARD4 ("E")
#define REWARD5 ("D")
#define REWARD6 ("C")
#define REWARD7 ("B")

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
    
    /**
     *  self function
     *
     *  @param touch
     *  @param event
     *
     *  @return
     */
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    virtual void update(float delta);
    
    void getReword();
    bool isInside(cocos2d::CCSprite *sprite,cocos2d::CCPoint point);
    
    /**
     *  attribute
     */
    cocos2d::CCSprite *disk;
    cocos2d::CCSprite *point;
    float diskRotation;
    float angleBeforeTouchesEnd;
    float finalAngel;
    bool canRotate;
};

#endif // __HELLOWORLD_SCENE_H__
