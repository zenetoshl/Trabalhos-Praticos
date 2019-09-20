#https://scikit-image.org/docs/dev/auto_examples/features_detection/plot_glcm.html
import matplotlib.pyplot as plt
from skimage.feature import greycomatrix, greycoprops
from skimage import data

TAMANHO_RECORTE = 21

# abre a imagem_ORIGINAL CAMERA, contida em skimage.data
image = data.camera()

# seleciona alguns recortes da imagem_ORIGINAL da grama
grama_POSICAO = [(474, 291), (440, 433), (466, 18), (462, 236)]
grama_recorte = []
for loc in grama_POSICAO:
    grama_recorte.append(image[loc[0]:loc[0] + TAMANHO_RECORTE,
                               loc[1]:loc[1] + TAMANHO_RECORTE])

# seleciona alguns recortes da imagem_ORIGINAL do ceu
ceu_POSICAO = [(54, 48), (21, 233), (90, 380), (195, 330)]
ceu_recorte = []
for loc in ceu_POSICAO:
    ceu_recorte.append(image[loc[0]:loc[0] + TAMANHO_RECORTE,
                             loc[1]:loc[1] + TAMANHO_RECORTE])

# calcula apenas dissimilaridade e correlação de cada recorte.
eixo_X = []
eixo_Y = []
for recorte in (grama_recorte + ceu_recorte):
    glcm = greycomatrix(recorte, [5], [0], 256, symmetric=True, normed=True)
    eixo_X.append(greycoprops(glcm, 'dissimilarity')[0, 0])
    eixo_Y.append(greycoprops(glcm, 'correlation')[0, 0])
# inicializa a figuracreate the figure
fig = plt.figure(figsize=(8,8))
#mostra a imagem_ORIGINAL original com a localizacao dos recortes
figura1 = fig.add_subplot(3, 2, 1)
figura1.imshow(image, cmap=plt.cm.gray, interpolation='nearest',
          vmin=0, vmax=255)
for (y, x) in grama_POSICAO:
    figura1.plot(x + TAMANHO_RECORTE / 2, y + TAMANHO_RECORTE / 2, 'rs')
for (y, x) in ceu_POSICAO:
    figura1.plot(x + TAMANHO_RECORTE / 2, y + TAMANHO_RECORTE / 2, 'bs')
figura1.set_xlabel('IMAGEM Original ')
figura1.set_xticks([])
figura1.set_yticks([])
figura1.axis('image')

# para cada  recorte, plota (dissimilarity, correlation)
figura1 = fig.add_subplot(3, 2, 2)
figura1.plot(eixo_X[:len(grama_recorte)], eixo_Y[:len(grama_recorte)], 'rx',  label='grama')
figura1.plot(eixo_X[len(grama_recorte):], eixo_Y[len(grama_recorte):], 'b*',  label='ceu')
figura1.set_xlabel('GLCM DISSIMILARIDADE')
figura1.set_ylabel('GLCM CORRELACAO')
figura1.legend()


# mostra a figura final
fig.suptitle('Usando GLCM', fontsize=14)
plt.show()
