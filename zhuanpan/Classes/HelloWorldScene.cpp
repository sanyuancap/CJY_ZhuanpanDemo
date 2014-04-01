#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    diskRotation = 0.0;
    angleBeforeTouchesEnd = 0.0;
    finalAngel = 0.0;
    canRotate = true;
    
    
    disk = CCSprite::create(DISK_NAME);
    disk->setPosition(ccp(size.width/2, size.height/2) );
    addChild(disk);
    
    point = CCSprite::create(POINT_NAME);
    point->setPosition(ccp(disk->getPositionX(), disk->getPositionY() ));
    addChild(point);
    
    setTouchEnabled(true);
    scheduleUpdate();
    return true;
}
/**
 *  注册触摸监听
 */
void HelloWorld::registerWithTouchDispatcher()
{
    //注册触摸监听
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}
/**
 *  点击事件
 *
 *  @param touch
 *  @param event
 *
 *  @return
 */

bool HelloWorld::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint nowlocation = touch->getLocationInView();
    if (!isInside(disk, nowlocation)) {
        return false;
    }
    if (!canRotate) {
        return false;
    }
    angleBeforeTouchesEnd = 0;
    return true;
}
void HelloWorld::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint prelocation = pTouch->getPreviousLocation();
	CCPoint nowlocation = pTouch->getLocation();

    //获取第一个向量
    CCPoint preVector = ccpSub(prelocation, disk->getPosition());
    float preAngle = -ccpToAngle(preVector);
    float prePoint = CC_RADIANS_TO_DEGREES(preAngle);

    //获取第二个
    CCPoint nowVector = ccpSub(nowlocation, disk->getPosition());
    float nowAngle = -ccpToAngle(nowVector);
    float nowPoint = CC_RADIANS_TO_DEGREES(nowAngle);

    
    
    CCLOG("prePoint:%f",prePoint);
    CCLOG("nowPoint:%f",nowPoint);
    //差值
    angleBeforeTouchesEnd = nowPoint - prePoint;
    diskRotation += nowPoint - prePoint;

    if (diskRotation < 0 ) {
        diskRotation = 0.0;
        angleBeforeTouchesEnd = 0.0;
    }else {
        
        canRotate = false;
    }
}
void HelloWorld::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}
void HelloWorld::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}
/**
 *  更新函数
 *
 *  @param delta
 */
void HelloWorld::update(float delta)
{
    
    disk->setRotation(diskRotation);
    if (fabs(angleBeforeTouchesEnd) > 0.1) {
        angleBeforeTouchesEnd = angleBeforeTouchesEnd * 0.99;
        diskRotation += angleBeforeTouchesEnd;
        /**
         *  计算奖励
         */
    }else{
        angleBeforeTouchesEnd = 0;
        getReword();
    }
    
}
/**
 *  判断点击是否在精灵内
 */
bool HelloWorld::isInside(cocos2d::CCSprite *sprite, cocos2d::CCPoint point)
{
    CCPoint orign = sprite->getPosition();
    float radius = sprite->getTextureRect().size.width / 2;
    float length = ccpDistance(orign, point);
    if (radius > length ) {
        return true;
    }else{
        return false;
    }
}
/**
 *  获得的奖品
 */
void HelloWorld::getReword()
{
    
    finalAngel = fmod(disk->getRotation(), 360);//最后角度
    int rewardIndex;//获奖角标
    CCLOG("角度：%f",finalAngel);
    
    if (finalAngel < ANGEL_REWARD0) {
        rewardIndex = 0;
    }else if (finalAngel < ANGEL_REWARD1){
        rewardIndex = 1;
    }else if (finalAngel < ANGEL_REWARD2){
        rewardIndex = 2;
    }else if (finalAngel < ANGEL_REWARD3){
        rewardIndex = 3;
    }else if (finalAngel < ANGEL_REWARD4){
        rewardIndex = 4;
    }else if (finalAngel < ANGEL_REWARD5){
        rewardIndex = 5;
    }else if (finalAngel < ANGEL_REWARD6){
        rewardIndex = 6;
    }else if (finalAngel < ANGEL_REWARD7){
        rewardIndex = 7;
    }
    
    switch (rewardIndex) {
        case 0:
            CCLOG("the reward is :%s",REWARD0);
            break;
        case 1:
            CCLOG("the reward is :%s",REWARD1);
            break;
            
        case 2:
            CCLOG("the reward is :%s",REWARD2);
            break;
            
        case 3:
            CCLOG("the reward is :%s",REWARD3);
            break;
            
        case 4:
            CCLOG("the reward is :%s",REWARD4);
            break;
            
        case 5:
            CCLOG("the reward is :%s",REWARD5);
            break;
            
        case 6:
            CCLOG("the reward is :%s",REWARD6);
            break;
            
        case 7:
            CCLOG("the reward is :%s",REWARD7);
            break;
            
            
        default:
            break;
    }
}
















