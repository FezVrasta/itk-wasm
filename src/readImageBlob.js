import createWebworkerPromise from './createWebworkerPromise'
import { readAsArrayBuffer } from 'promise-file-reader'

import Image from "../core/Image.js"

import config from './itkConfig'

const readImageBlob = (webWorker, blob, fileName, mimeType) => {
  let worker = webWorker
  return createWebworkerPromise('ImageIO', worker)
    .then(({ webworkerPromise, worker: usedWorker }) => {
      worker = usedWorker
      return readAsArrayBuffer(blob)
        .then((arrayBuffer) => {
          return webworkerPromise.postMessage(
            {
              operation: 'readImage',
              name: fileName,
              type: mimeType,
              data: arrayBuffer,
              config: config
            },
            [arrayBuffer]
          )
        }).then(function (image: Image) {
          return Promise.resolve({ image, webWorker: worker as Worker })
        })
    })
}

export default readImageBlob
