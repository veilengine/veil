# Veil

Veil is a new game engine intended to cleanly separate game logic like AI from
systems logic like rendering, input and sound.

It is very young and thus also very experimental at this stage. Expect lots of
major breaking changes in the near future. The codebase is pretty small, so
feel free to dig in and see how it works.

# TODO:
- Move SDL stuff to a separate project namespaced in Veil::SDL
- Expand SDLInput to allow registration of lambdas to handle keypresses
- Make SDLRenderer track entity changes and reload textures, if applicable
- Add plane flipping via SDL_RendererFlip (Negative scale, maybe?)
- Add Origin component to move rotation point
- Add Scale component
- Create window from renderer, entity object is hack-ish
- Multi-window support

### Copyright (c) 2014 Stephen Belanger
#### Licensed under MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
