import sys
from PIL import Image, ImageFilter
def main(argv):
    img = Image.open(argv)
    img.load()
    background = Image.new("RGB",img.size,(255, 255, 255))
    background.paste(img, mask=img.split()[3])
    im = background.convert('L')

    newImage = Image.new('L', (28, 28), (255))
    width = float(im.size[0])
    height = float(im.size[1])
    nwidth = int(round((20.0/height*width),0))
    if (nwidth == 0):
        nwidth = 1
    img = im.resize((nwidth,20), Image.ANTIALIAS).filter(ImageFilter.SHARPEN)
    wleft = int(round(((28 - nwidth)/2),0))
    newImage.paste(img, (wleft, 4))
    newImage.save("sample.png")
if __name__ == "__main__":
    main(sys.argv[1])
