#ifndef LINTHESIA_ONE_PLAYER_SCREEN_H
#define LINTHESIA_ONE_PLAYER_SCREEN_H

#include "libmidi/midi.h"

#include "screens/abstract_screen.h"
#include "screens/screens.h"
#include "keyboard/keyboard.h"
#include "keyboard/trail.h"
#include "note_ground.h"


namespace linthesia {

/**
 * Represent the screen for one player to play a song
 * @class OnePlayerScreen
 */
class OnePlayerScreen : public AbstractScreen {

    public:
        const static ScreenIndex INDEX;
        ScreenIndex run(
            sf::RenderWindow &app,
            Context &context
        );


    private:
        /**
         * Arbitrary height at the bottom that we will use latter to put score
         * play/pause buttons etc.
         */
        const unsigned SPACE_BUTTONS = 60;

        /**
         *
         */
        void setKeyboardPosition(const sf::RenderWindow &app);
        Keyboard keyboard;

        /**
         * set the "separator" (the "trail") at the top of the keyboard
         */
        void setKeyboardTrailPosition(
            const sf::RenderWindow &app
        );
        KeyboardTrail keyboardTrail;

        /**
         *
         */
        void setNoteGroundPosition(
            const sf::RenderWindow &app
        );
        NoteGround noteGround;

        /**
         * Play the part of the song that should be played during that
         * delta time
         */
        void playSong(
            linthesia::Context &context,
            const sf::Time& delta
        );

        /**
         * Update the keyboard on screen according to input notes
         */
        void updateKeyboard(
            const MidiEventList& inputNotes,
            linthesia::Context &context
        );
};


}
#endif

