#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QTimer>
#include "musicobject.h"
#include "musicglobaldefine.h"

#ifdef Q_CC_GNU
#  pragma GCC diagnostic ignored "-Wswitch"
#endif

class SoundCore;
class MusicPlayedlist;

/*! @brief The class of the music player.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_CORE_EXPORT MusicPlayer : public QObject
{
    Q_OBJECT
public:
    enum Enhanced
    {
        EnhancedOff,    /*!< enhanced off, no any effect*/
        Music3D,        /*!< 3d music effect*/
        MusicNICAM,     /*!< nicam music effect*/
        MusicSubwoofer, /*!< subwoofer music effect*/
        MusicVocal      /*!< vocal music effect*/
    };

    /*!
     * Object contsructor.
     */
    explicit MusicPlayer(QObject *parent = 0);

    ~MusicPlayer();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Get current player is playing or not.
     */
    bool isPlaying() const;
    /*!
     * Get current player state.
     */
    MusicObject::PlayState state() const;
    /*!
     * Set current play list.
     */
    void setPlaylist(MusicPlayedlist *playlist);
    /*!
     * Get current play list.
     */
    MusicPlayedlist *playlist() const;

    /*!
     * Get current player duration.
     */
    qint64 duration() const;
    /*!
     * Get current player postion.
     */
    qint64 position() const;

    /*!
     * Set current player to next music.
     */
    void playNext();
    /*!
     * Set current player to previous music.
     */
    void playPrevious();

    /*!
     * Get current player volume.
     */
    int volume() const;
    /*!
     * Set current player volume.
     */
    void setVolume(int volume);
    /*!
     * Get current player mute state.
     */
    bool isMuted() const;
    /*!
     * Set current player mute or not.
     */
    void setMuted(bool muted);
    /*!
     * Set current play pos.
     */
    void setPosition(qint64 position);

    /*!
     * Set current music enhanced effect.
     */
    void setMusicEnhanced(Enhanced type);
    /*!
     * Get current music enhanced effect.
     */
    Enhanced getMusicEnhanced() const;

Q_SIGNALS:
    /*!
     * Current state changed.
     */
    void stateChanged(MusicObject::PlayState newState);
    /*!
     * Current duration changed.
     */
    void durationChanged(qint64 duration);
    /*!
     * Current position changed.
     */
    void positionChanged(qint64 position);
    /*!
     * Current volume changed.
     */
    void volumeChanged(int volume);
    /*!
     * Current mute state changed.
     */
    void mutedChanged(bool muted);

public Q_SLOTS:
    /*!
     * Player to play.
     */
    void play();
    /*!
     * Player to pause.
     */
    void pause();
    /*!
     * Player to stop.
     */
    void stop();
    /*!
     * Set current equalizer effect.
     */
    void setEqEffect(const MusicObject::MIntList &hz);
    /*!
     * Set enable to set current equalizer effect.
     */
    void setEnaleEffect(bool enable);
    /*!
     * Read equalizer effect from config file.
     */
    void setEqInformation();
    /*!
     * Set current player volume.
     */
    void setSoundEffectVolume(int value);
    /*!
     * Remove current music media data.
     */
    void removeCurrentMedia();

private Q_SLOTS:
    /*!
     * Player one second time out.
     */
    void update();
    /*!
     * Get current duration by time out.
     */
    void getCurrentDuration();

protected:
    /*!
     * Set current music enhanced effect option.
     */
    void setMusicEnhancedCase();

    MusicPlayedlist *m_playlist;
    MusicObject::PlayState m_state;
    SoundCore *m_music;
    QTimer m_timer;
    QString m_currentMedia;
    Enhanced m_musicEnhanced;
    qint64 m_duration;

    int m_tryTimes;
    int m_volumeMusic3D, m_balance;
    float m_posOnCircle;

};

#endif // MUSICPLAYER_H
