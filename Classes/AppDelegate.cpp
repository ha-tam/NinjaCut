#include "AppDelegate.h"
#include "gameScene.h"
#include "Menu.h"
#include "SimpleAudioEngine.h"
// is the game landscape or portrait (true for landscape and false for portrait)
#define IS_LANDSCAPE true

USING_NS_CC;

AppDelegate::AppDelegate() {
    
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("No More Studies !!!?");
        director->setOpenGLView(glview);
    }
    glview->setDesignResolutionSize(1280,720,ResolutionPolicy::SHOW_ALL);
	glview->setFrameSize(1280, 720);
    // turn on display FPS
    director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->preloadBackgroundMusic("macicbg.wav");
	audio->preloadEffect("cut01.mp3");
	audio->preloadEffect("argh.wav");
	audio->preloadEffect("kya.wav");
	audio->preloadEffect("rdygo.wav");
	audio->playBackgroundMusic("macicbg.wav", true);
	audio->setBackgroundMusicVolume(0.3);

    // run
    //auto scene = gameLayer::createScene();
    auto scene = gameMenu::createScene(0);
    director->runWithScene(scene);
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    
    // if you use SimpleAudioEngine, it must be pause
     CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    
    // if you use SimpleAudioEngine, it must resume here
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
